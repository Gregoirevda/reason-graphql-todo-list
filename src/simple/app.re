open Types;

type state = {
    todos: list todo
};

let se = ReasonReact.stringToElement;
let lastTodoId = 0;

let component = ReasonReact.statefulComponent "Page";

let make children => {
  {
    ...component,
    initialState: fun () => {
        todos: []
    },
    render: fun {state: {todos}, update} => {
    let numOfItems = List.length todos;
    <header className="header">
        <h1>(ReasonReact.stringToElement "Todos")</h1>
        <input
            className="new-todo"
            placeholder="What needs to be done?"
        />
        <TodoList todos />
/*
        (ReasonReact.createElement (TodoList.make todos children))
*/

        <div> (se (string_of_int numOfItems)) </div>
        <button
            onClick=(update (fun event {state} => {
                ReasonReact.Update {
                    todos: [
                        {
                            title: "HI",
                            id: lastTodoId + 1
                        },
                        ...state.todos
                    ]
                }
            }))
        > (se "CLICK") </button>
    </header>
    }
  }
};



