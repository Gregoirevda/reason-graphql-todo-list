open Types;
let component = ReasonReact.statelessComponent "Todo";
let make ::todo ::toggleTodo _children => {
  ...component,
  render: fun _self =>
<li>
    <div className="view">
        <input
            className="toggle"
            _type="checkbox"
            checked=(Js.Boolean.to_js_boolean todo.active)
            onChange=(fun _event => toggleTodo())
        />
        <label>
            (ReasonReact.stringToElement todo.title)
        </label>
        <button className="destroy" />
    </div>
</li>
};
