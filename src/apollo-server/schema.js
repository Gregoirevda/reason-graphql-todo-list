// Welcome to Launchpad!
// Log in to edit and save pads, run queries in GraphiQL on the right.
// Click "Download" above to get a zip with a standalone Node.js server.
// See docs and examples at https://github.com/apollographql/awesome-launchpad

// graphql-tools combines a schema string with resolvers.
const {makeExecutableSchema} = require('graphql-tools');

let todos = [{ id: "1", active: true, title: "One"},
  { id: "2", active: false, title: "Two"}];

// Construct a schema, using GraphQL schema language
const typeDefs = `
	input TodoInput {
		title: String!
    active: Boolean!
	}

	type Todo {
		id: ID!
    title: String!
    active: Boolean!
	}

  type Query {
    todos: [Todo]
  }

	type Mutation {
		deleteTodo(id: ID!): [Todo]
		toggleTodo(id: ID!): [Todo]
		addTodo(title: String!, active: Boolean!): [Todo]
	}
`;

// Provide resolver functions for your schema fields
const resolvers = {
  Query: {
    todos: () => {
      return todos;
    },
  },
  Mutation: {
    deleteTodo: (_, {id}) => {
      todos = todos.filter(todo => todo.id !== id);
      return todos;
    },
    toggleTodo: (_, {id}) => {
      todos = todos.map(todo =>
        todo.id === id ? Object.assign({}, todo, {active: !todo.active}) : todo
      );
      return todos;
    },
    addTodo: (_, {title, active}) => {
      todos = [
        ...todos, {
          id: todos.reduce((id, todo) => parseInt(todo.id, 10) + 1, 1),
          title,
          active
        }];
      return todos;
    }
  }
};

// Required: Export the GraphQL.js schema object as "schema"
exports.schema = makeExecutableSchema({
  typeDefs,
  resolvers,
});

