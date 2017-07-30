type networkInterface = Js.t {
    .
    uri: string
};

type apolloClient = {
 networkInterface: string
};

external apollo_client: apolloClient => string = "ApolloClient" [@@bs.new] [@@bs.module "react-apollo"];
external create_network_interface: networkInterface => string = "createNetworkInterface" [@@bs.module "react-apollo"];

let networkInterfaceInstance = {"uri": "http://api.githunt.com/graphql"};

let apolloClientInstance = {
 networkInterface: create_network_interface networkInterfaceInstance
};

let inst = apollo_client apolloClientInstance;
