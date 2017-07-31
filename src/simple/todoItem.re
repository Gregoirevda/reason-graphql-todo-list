open Types;

let component = ReasonReact.statelessComponent "Todo";

let make ::todo ::toggleTodo ::deleteTodo _children => {
  ...component,
  render: fun _self =>
    <li className=(todo.active ? "" : "completed")>
      <div className="view">
        <input className="toggle" _type="checkbox" onChange=(fun _event => toggleTodo ()) />
        <label> (ReasonReact.stringToElement todo.title) </label>
        <button className="destroy" onClick=(fun _event => deleteTodo ()) />
      </div>
    </li>
};
