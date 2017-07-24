let component = ReasonReact.statelessComponent "Todo";
let make ::name _children => {
  ...component,
  render: fun _self => <div>
    (ReasonReact.stringToElement name)
  </div>
};