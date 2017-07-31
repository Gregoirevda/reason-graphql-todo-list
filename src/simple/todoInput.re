let valueFromEvent event :string => (
                                      event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj
                                    )##value;

let component = ReasonReact.statefulComponent "Greeting";

let make ::addTodo _children => {
  ...component,
  initialState: fun () => "",
  render: fun {state: text, update} =>
    <input
      className="new-todo"
      placeholder="What needs to be done?"
      value=text
      _type="text"
      onChange=(update (fun event {state: text} => ReasonReact.Update (valueFromEvent event)))
      onKeyDown=(
        update (
          fun event _ =>
            if (ReactEventRe.Keyboard.key event == "Enter") {
              addTodo text;
              ReasonReact.Update ""
            } else {
              ReasonReact.NoUpdate
            }
        )
      )
    />
};
