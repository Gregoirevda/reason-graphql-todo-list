open Types;
let component = ReasonReact.statelessComponent "Todo";
let make ::todo(todo: todo) _children => {
  ...component,
  render: fun _self => <div>
    (ReasonReact.stringToElement todo.title)
  </div>
};
