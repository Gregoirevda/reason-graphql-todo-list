const express = require('express');
const bodyParser = require('body-parser');
const {graphqlExpress} = require('apollo-server-express');
const {schema} = require('./schema');
const cors = require('cors');

const PORT = 3010;

const app = express();

app.use(cors());

// bodyParser is needed just for POST.
app.use('/graphql', bodyParser.json(), graphqlExpress({ schema: schema }));

app.listen(PORT, () => {
  console.log('server listening on localhost:', PORT);
});