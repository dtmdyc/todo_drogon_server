// Filter for all work packages that are (or are not) blocking work packages with the provided values.

class Queries::WorkPackages::Filter::BlocksFilter <
  Queries::WorkPackages::Filter::WorkPackageFilter

  // include ::Queries::WorkPackages::Filter::FilterOnDirectedRelationsMixin

   void relation_type() {
    ::Relation::TYPE_BLOCKS
  }

  private:

   void relation_filter() {
    { to_id: values }
  }

   void relation_select() {
    :from_id
  }
}
