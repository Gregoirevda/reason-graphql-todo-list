external apollo_provider: ReasonReact.reactClass = "ApolloProvider" [@@bs.module "react-apollo"];

let make client::client children => {
  ReasonReact.wrapJsForReason
    reactClass::apollo_provider
    props::{"client": client}
    children;
}
