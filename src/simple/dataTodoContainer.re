open Types;

external gql : gql = "graphql-tag" [@@bs.module];

external graphql : graphql = "graphql" [@@bs.module "react-apollo"];

let todos_query =
  gql {|
  query getAllTodos {
    todos {
      id
      title
      active
    }
  }
|} [@bs];


let todos_query_config = {
    name: "todosQuery"
};

let add_todo_mutation =
  gql {|
  mutation addTodo($title: String!, $active: Boolean!) {
    addTodo(
        title: $title,
        active: $active
    ) {
      id
      title
      active
    }
  }
|} [@bs];

let addTodoWrapper = graphql add_todo_mutation [@bs];
let wrappedAddTodoComponent: ReasonReact.reactClass = addTodoWrapper TodoContainer.jsComponent [@bs];

let queryWrapper = graphql todos_query [@bs];
let wrappedQueryTodosComponent: ReasonReact.reactClass = queryWrapper wrappedAddTodoComponent [@bs];

/*
 * this is unfortunate (but legit, and a supported use-case of ReasonReact). See
 * the comment in todoContainer, at the end. In the future, hopefully we can cut
 * out the js part in reason->js->js->reason */
let make children =>
  ReasonReact.wrapJsForReason reactClass::wrappedQueryTodosComponent props::(Js.Obj.empty ()) children;
