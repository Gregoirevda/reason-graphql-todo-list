type todo = {
    id: int
};

type state = {
    todos: list string
};

let component = ReasonReact.statefulComponent "Page";

let make _children => {
  {
    ...component,
    initialState: fun () => {
        todos: ["hello", "world", "how are "]
    },
    render: fun self => {
    let todos = List.map (fun todo => ReasonReact.stringToElement todo) self.state.todos;
    let title = "Todos";
    <header className="header">
        <h1>(ReasonReact.stringToElement title)</h1>
        <input
            className="new-todo"
            placeholder="What needs to be done?"
        />
        <div> (ReasonReact.arrayToElement (Array.of_list todos)) </div>
    </header>
    }
  }
};



