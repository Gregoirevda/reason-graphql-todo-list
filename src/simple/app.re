let component = ReasonReact.statelessComponent "ApolloProviderLink";

let make _children => {
    ...component,
    render: fun _self => {
        <ApolloProvider client=(ApolloClient.inst)>
          <TodoContainer/>
        </ApolloProvider>
    }
};
