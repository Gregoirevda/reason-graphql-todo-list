open Types;
external gql: gql = "graphql-tag" [@@bs.module];

type state = {
    todos: list todo,
};

let se = ReasonReact.stringToElement;
let lastTodoId = ref 0;

let component = ReasonReact.statefulComponent "Page";

let make _children => {
    ...component,
    initialState: fun () => {
        todos: []
    },
    render: fun {state: {todos}, update} => {
    let numOfItems = List.length todos;
    <header className="header">
        <h1>(ReasonReact.stringToElement "Todos")</h1>
        <TodoInput addTodo=(update (fun text {state} => {
            lastTodoId := !lastTodoId + 1;
            ReasonReact.Update {
                todos:  [
                    {
                        id: !lastTodoId,
                        title: text,
                        active: true
                    },
                    ...state.todos
                ]
            }
        }))/>
        <TodoList
            todos
            toggleTodo=(update (fun id {state} => {
                ReasonReact.Update {
                    todos: List.map (fun todo => todo.id === id ? {
                        id: todo.id,
                        active: not todo.active,
                        title: todo.title
                    } : todo) state.todos
                }
            }))
            deleteTodo=(update (fun id {state} => {
                ReasonReact.Update {
                    todos: List.filter (fun todo => todo.id !== id) state.todos
                }
            }))
        />

        <div>
            (se ( "Amount of todos: " ^ string_of_int (List.length todos)))
        </div>
    </header>
    }
};
