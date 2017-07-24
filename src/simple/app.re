type todo = {
    id: int
};

type state = {
    todos: array string
};

let component = ReasonReact.statefulComponent "Page";

let make _children => {
  {
    ...component,
    initialState: fun () => {
        todos: [|"hello", "world", "how are you"|]
    },
    render: fun self => {
    let todos = Array.map (fun todo => ReasonReact.stringToElement todo) self.state.todos;
    let title = "Todos";
    <header className="header">
        <h1>(ReasonReact.stringToElement title)</h1>
        <input
            className="new-todo"
            placeholder="What needs to be done?"
        />
        <div> (ReasonReact.arrayToElement todos) </div>
    </header>
    }
  }
};



