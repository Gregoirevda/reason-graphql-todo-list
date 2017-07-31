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

let wrapper = graphql todos_query [@bs];

let wrappedComponent: ReasonReact.reactClass = wrapper TodoContainer.jsComponent [@bs];

/*
 * this is unfortunate (but legit, and a supported use-case of ReasonReact). See
 * the comment in todoContainer, at the end. In the future, hopefully we can cut
 * out the js part in reason->js->js->reason */
let make children =>
  ReasonReact.wrapJsForReason reactClass::wrappedComponent props::(Js.Obj.empty ()) children;
