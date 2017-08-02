open Types;

external apollo_client : apolloClient => string =
  "ApolloClient" [@@bs.new] [@@bs.module "react-apollo"];

external create_network_interface : networkInterface => string =
  "createNetworkInterface" [@@bs.module "react-apollo"];

let networkInterfaceInstance = {"uri": "http://localhost:3010/graphql"};

let apolloClientInstance = {"networkInterface": create_network_interface networkInterfaceInstance};
let instance = apollo_client apolloClientInstance;