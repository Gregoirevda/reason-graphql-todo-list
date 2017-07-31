open Types;


type state = {
    todos: list todo
};

type response = {
    todos: list todo,
    loading : bool
};

type propsType = {
    data: response
};

let se = ReasonReact.stringToElement;

let lastTodoId = ref 0;

let component = ReasonReact.statefulComponent "Page";

let make ::response _children => {
  ...component,
  initialState: fun () => {
    todos: response.loading ? [] : response.todos
  },
  render: fun {state: {todos}, update} => {
    Js.log response;
    let numOfItems = List.length todos;
    <header className="header">
      <h1> (ReasonReact.stringToElement "Todos") </h1>
      <TodoInput
        addTodo=(
          update (
            fun text {state} => {
              lastTodoId := !lastTodoId + 1;
              ReasonReact.Update {
                todos: [{id: !lastTodoId, title: text, active: true}, ...state.todos]
              }
            }
          )
        )
      />
      <TodoList
        todos=todos
        toggleTodo=(
          update (
            fun id {state} =>
              ReasonReact.Update {
                todos:
                  List.map
                    (
                      fun todo =>
                        todo.id === id ?
                          {id: todo.id, active: not todo.active, title: todo.title} : todo
                    )
                    state.todos
              }
          )
        )
        deleteTodo=(
          update (
            fun id {state} =>
              ReasonReact.Update {
                todos: List.filter (fun todo => todo.id !== id) state.todos
              }
          )
        )
      />
      <div> (se ("Amount of todos: " ^ string_of_int (List.length todos))) </div>
    </header>
  }
};

/*
 * Why are we exposing this JS interop, even though this file's only used by the
 * Reason side? Because the higher-order function returned by the `graphql` call
 * (wrapper, in dataTodoContainer) asks as an input the backing ReactJS class,
 * which Reason circumvents, and only exposes when some JS calls really needs
 * it. Remember that a ReasonReact "class" isn't a ReactJS class.
 */
let jsComponent = ReasonReact.wrapReasonForJs ::component (fun props =>
    make response::props.data [||]
);
