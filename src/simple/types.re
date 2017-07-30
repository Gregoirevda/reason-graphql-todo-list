type todo = {
    id: int,
    title: string,
    active: bool
};

type gql = string => string;
type stuff = {
  state: string,
  noRetainedProps: string,
  componentSpec: string
};
type graphql = string => ReasonReact.reactElement => array ReasonReact.reactElement => ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
/*  */

type networkInterface = Js.t {
    .
    uri: string
};

type apolloClient = {
 networkInterface: string
};
