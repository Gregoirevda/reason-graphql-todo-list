open Types;

external gql : gql = "graphql-tag" [@@bs.module];

external graphql : graphql = "graphql" [@@bs.module "react-apollo"];

external graphqlWithConfig : graphqlWithConfig = "graphql" [@@bs.module "react-apollo"];

/* usage: graphqlWithConfig todos_query (graphqlConfig name::"foo" ())  */
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

let add_todo_mutation =
  gql
  {|
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
|}
  [@bs];

let toggle_todo_mutation =
  gql
  {|
    mutation toggleTodo($id: ID!) {
        toggleTodo(id: $id) {
          id
          title
          active
        }
    }
|}
  [@bs];

let delete_todo_mutation =
  gql
  {|
    mutation deleteTodo($id: ID!) {
        deleteTodo(id: $id) {
          id
          title
          active
        }
    }
|}
  [@bs];


let addTodoWrapper = graphqlWithConfig add_todo_mutation (graphqlConfig name::"addTodoMutation" ()) [@bs];

let wrappedAddTodoComponent: ReasonReact.reactClass =
  addTodoWrapper TodoContainer.jsComponent [@bs];

let queryWrapper = graphqlWithConfig todos_query (graphqlConfig name::"todosQuery"()) [@bs];

let wrappedQueryTodosComponent: ReasonReact.reactClass =
  queryWrapper wrappedAddTodoComponent [@bs];

let toggleTodoWrapper = graphqlWithConfig toggle_todo_mutation (graphqlConfig name::"toggleTodoMutation"()) [@bs];

let wrappedToggleTodoMutationComponent: ReasonReact.reactClass =
  toggleTodoWrapper wrappedQueryTodosComponent [@bs];

let deleteTodoWrapper = graphqlWithConfig delete_todo_mutation (graphqlConfig name::"deleteTodoMutation"()) [@bs];

let wrappedDeleteTodoMutationComponent: ReasonReact.reactClass =
  deleteTodoWrapper wrappedToggleTodoMutationComponent [@bs];

/*
 * this is unfortunate (but legit, and a supported use-case of ReasonReact). See
 * the comment in todoContainer, at the end. In the future, hopefully we can cut
 * out the js part in reason->js->js->reason */
let make children =>
  ReasonReact.wrapJsForReason
    reactClass::wrappedDeleteTodoMutationComponent props::(Js.Obj.empty ()) children;
