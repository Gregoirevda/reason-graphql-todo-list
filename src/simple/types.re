type todo = {
  id: int,
  title: string,
  active: bool
};

/* we give the query (under the hood, it's a string) an opaque type. This way nobody can accidentally use it as a string  */
type query;
type apolloConfig = Js.t {
    .
    name: string
};

/*
 * annotate the function with [@bs] so that it's statically verified to be fully
 * applied at each callsite. Better perf from fewer curryings. See more info on
 * `[@bs]` in the BS manual
 */
type gql = (string => query) [@bs];

type wrapper = (ReasonReact.reactClass => ReasonReact.reactClass) [@bs];

type graphql_config = Js.t {.
    name: string
};

type graphql = (query => wrapper) [@bs];

type stuff = {
  state: string,
  noRetainedProps: string,
  componentSpec: string
};

type networkInterface = Js.t {. uri : string};

type apolloClient = Js.t {. networkInterface: string};
