open Types;

let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent "TodosList";

let make ::todos ::toggleTodo ::deleteTodo _children => {
  ...component,
  render: fun self => {
    <section className="main">
          <ul className="todo-list">
            (
              ReasonReact.arrayToElement (
                Array.of_list (
                  List.map
                    (
                      fun todo => {
                        <TodoItem
                          key=(todo##id)
                          todo
                          toggleTodo=(fun _ => toggleTodo todo##id)
                          deleteTodo=(fun _ => deleteTodo todo##id)
                        />
                      }
                    )
                    todos
                )
              )
            )
          </ul>
        </section>
  }
};
