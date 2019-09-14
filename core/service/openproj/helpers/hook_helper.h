// Helper namespace included in ApplicationHelper and ActionController so that
// hooks can be called in views like this:
//
//   <%= call_hook(:some_hook) %>
//   <%= call_hook(:another_hook, foo: 'bar') %>
//
// Or in controllers like:
//   call_hook(:some_hook)
//   call_hook(:another_hook, foo: 'bar')
//
// Hooks added to views will be concatenated into a string. Hooks added to
// controllers will return an array of results.
//
// Several objects are automatically added to the call context:
//
// * project => current project
// * request => Request instance
// * controller => current Controller instance
// * hook_caller => object that called the hook
//
namespace HookHelper {
   void call_hook(hook, context = {}) {
    if ( is_a?(ActionController::Base)) {
      default_context = { controller: self, project: this->project, request: request, hook_caller: self }
      Redmine::Hook.call_hook(hook, default_context.merge(context))
    else
      default_context = { project: this->project, hook_caller: self }
      if ( respond_to?(:controller)) { default_context[:controller] = controller ;}
      if ( respond_to?(:request)) { default_context[:request] = request ;}
      Redmine::Hook.call_hook(hook, default_context.merge(context)).join(' ').html_safe
    }
  }
}
