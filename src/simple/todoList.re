open Types;
let se = ReasonReact.stringToElement;
let component = ReasonReact.statelessComponent "TodosList";
let make ::todos ::toggleTodo _children => {
    {
        ...component,
        render: fun self => {
            <section className="main">
                <ul className="todo-list">
                    (
                        ReasonReact.arrayToElement
                        (
                            Array.of_list
                            (List.mapi (fun index todoItem => {
                                <TodoItem
                                    key=(string_of_int index)
                                    todo=todoItem
                                    toggleTodo=(fun _ => toggleTodo(index))
                                />
                            }) todos)
                        )
                    )
                </ul>
            </section>
        }
    }
};
