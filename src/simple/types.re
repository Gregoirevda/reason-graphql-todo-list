type todo = {
    id: int,
    title: string,
    active: bool
};

type gql = ();

type networkInterface = Js.t {
    .
    uri: string
};

type apolloClient = {
 networkInterface: string
};
