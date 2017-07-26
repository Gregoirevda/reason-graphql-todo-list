open Types;

type state = {
    todos: list todo,
    todoInput: string
};

let se = ReasonReact.stringToElement;
let lastTodoId = 0;

let component = ReasonReact.statefulComponent "Page";

let valueFromEvent event: string =>
    (event
        |> ReactEventRe.Form.target
        |> ReactDOMRe.domElementToObj
    )##value;

let make children => {
  {
    ...component,
    initialState: fun () => {
        todos: [],
        todoInput: ""
    },
    render: fun {state: {todos, todoInput}, update} => {
    let numOfItems = List.length todos;
    <header className="header">
        <h1>(ReasonReact.stringToElement "Todos")</h1>
        <input
            className="new-todo"
            placeholder="What needs to be done?"
            onChange=(update (fun event {state} =>
                ReasonReact.Update {
                    todoInput: (valueFromEvent event),
                    todos : state.todos
                }
            ))
            onKeyDown=(update (fun event {state} =>
                if(ReactEventRe.Keyboard.key event == "Enter") {
                    ReasonReact.Update {
                        todos: [{
                                title: state.todoInput,
                                id: lastTodoId + 1,
                                active: true
                            },
                            ...state.todos
                        ],
                        todoInput: ""
                    }
                } else {
                    ReasonReact.NoUpdate;
                }

            ))
        />
        <TodoList
            todos
            toggleTodo=(update (fun id {state} => {
                ReasonReact.Update {
                    todos: List.map (fun todo => todo.id === id ? todo : todo) state.todos,
                    todoInput: state.todoInput
                }
            }))
        />

        <div>
            (se ( "Amount of todos: " ^ string_of_int (List.length todos)))
        </div>
    </header>
    }
  }
};



