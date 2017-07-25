open Types;
let se = ReasonReact.stringToElement;
let component = ReasonReact.statelessComponent "TodosList";
let make ::todos(todos: list todo) _children => {
    {
        ...component,
        render: fun self => {
            <section className="main">
                <input
                    className="toggle-all"
                />
                <ul className="todo-list">
                    (se (string_of_int (List.length todos)))
                    (
                        ReasonReact.arrayToElement
                        (
                            Array.of_list
                            (List.mapi (fun index todo => {
                                <Todo
                                    key=(string_of_int index)
                                    todo
                                />
                            }

                            ) todos)
                        )
                    )
                </ul>
            </section>
        }
    }
};
