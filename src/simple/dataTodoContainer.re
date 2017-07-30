open Types;
external gql: gql = "graphql-tag" [@@bs.module];
external graphql: graphql = "graphql" [@@bs.module "react-apollo"];

let todos_query = gql {|
  query getAllTodos {
    todos {
      id
      title
      active
    }
  }
|};

let wrapper = graphql todos_query;
let make = wrapper <TodoContainer/>;
