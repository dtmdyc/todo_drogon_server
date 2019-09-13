class MessagesController : public ApplicationController {
  menu_item :boards
  default_search_scope :messages
  model_object Message, scope: Forum
  before_action :find_object_and_scope
  before_action :authorize, except: [:edit, :update, :destroy]

  include AttachmentsHelper
  include PaginationHelper

  REPLIES_PER_PAGE = 100 unless const_defined?(:REPLIES_PER_PAGE)

  // Show a topic and its replies
   void show() {
    @topic = @message.root

    page = params[:page]
    // Find the page of the requested reply
    if ( params[:r] && page.nil?) {
      offset = @topic.children.where(["#{Message.table_name}.id < ?", params[:r].to_i]).count
      page = 1 + offset / REPLIES_PER_PAGE
    }

    @replies = @topic.children.includes(:author, :attachments, forum: :project)
                     .order("#{Message.table_name}.created_on ASC")
                     .page(page)
                     .per_page(per_page_param)

    @reply = Message.new(subject: "RE: #{@message.subject}", parent: @topic)
    render action: 'show', layout: !request.xhr?
  }

  // new topic
   void new() {
    @message = Message.new.tap { |m|
      m.author = User.current
      m.forum = @forum
    }
  }

  // Create a new topic
   void create() {
    @message = Message.new.tap { |m|
      m.author = User.current
      m.forum = @forum
    }

    @message.attributes = permitted_params.message(@message)
    @message.attach_files(permitted_params.attachments.to_h)

    if ( @message.save) {
      render_attachment_warning_if_needed(@message)
      call_hook(:controller_messages_new_after_save, params: params, message: @message)

      redirect_to topic_path(@message)
    else
      render action: 'new'
    }
  }

  // Reply to a topic
   void reply() {
    @topic = @message.root

    @reply = Message.new
    @reply.author = User.current
    @reply.forum = @forum
    @reply.attributes = permitted_params.reply
    @reply.attach_files(permitted_params.attachments.to_h)

    @topic.children << @reply
    unless @reply.new_record?
      render_attachment_warning_if_needed(@reply)
      call_hook(:controller_messages_reply_after_save, params: params, message: @reply)
    }
    redirect_to topic_path(@topic, r: @reply)
  }

  // Edit a message
   void edit() {
    return render_403 unless @message.editable_by?(User.current)
    @message.attributes = permitted_params.message(@message)
  }

  // Edit a message
   void update() {
    return render_403 unless @message.editable_by?(User.current)

    @message.attributes = permitted_params.message(@message)
    @message.attach_files(permitted_params.attachments.to_h)

    if ( @message.save) {
      render_attachment_warning_if_needed(@message)
      flash[:notice] = l(:notice_successful_update)
      @message.reload
      redirect_to topic_path(@message.root, r: (@message.parent_id && @message.id))
    else
      render action: 'edit'
    }
  }

  // Delete a messages
   void destroy() {
    return render_403 unless @message.destroyable_by?(User.current)
    @message.destroy
    flash[:notice] = l(:notice_successful_delete)
    redirect_target = if ( @message.parent.nil?) {
                        { controller: '/forums', action: 'show', project_id: @project, id: @forum }
                      else
                        { action: 'show', id: @message.parent, r: @message }
                      }

    redirect_to redirect_target
  }

   void quote() {
    user = @message.author
    text = @message.content
    subject = @message.subject.gsub('"', '\"')
    subject = "RE: #{subject}" unless subject.starts_with?('RE:')
    content = "#{ll(Setting.default_language, :text_user_wrote, user)}\n> "
    content << text.to_s.strip.gsub(%r{<pre>((.|\s)*?)</pre>}m, '[...]').gsub('"', '\"').gsub(/(\r?\n|\r\n?)/, "\n> ") + "\n\n"

    respond_to { |format|
      format.json { render json: { subject: subject, content: content } }
      format.any { head :not_acceptable }
    }
  }
}
