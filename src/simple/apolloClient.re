open Types;

external apollo_client : apolloClient => string =
  "ApolloClient" [@@bs.new] [@@bs.module "react-apollo"];

external create_network_interface : networkInterface => string =
  "createNetworkInterface" [@@bs.module "react-apollo"];

let networkInterfaceInstance = {"uri": "https://5mql731v9.lp.gql.zone/graphqltest"};

let apolloClientInstance = {networkInterface: create_network_interface networkInterfaceInstance};

let instance = apollo_client apolloClientInstance;
