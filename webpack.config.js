const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const CleanWebpackPlugin = require('clean-webpack-plugin');

module.exports = {
  entry: {
    root: './src/simple/root.re',
    static: [
      './src/assets/todomvc-app-css/index.css',
      './src/assets/todomvc-common/base.css'
    ]
  },
  output: {
    path: path.resolve(__dirname, 'bundledOutputs'),
    filename: '[name].js',
  },
  devServer: {
    contentBase: './bundledOutputs'
  },
  plugins: [
    new CleanWebpackPlugin(['bundledOutputs']),
    new HtmlWebpackPlugin({
      title: 'ReasonML graphQL',
      template: 'src/assets/index.html'
    })
  ],
  module: {
    rules: [
      // Set up Reason and OCaml files to use the loader
      { test: /\.(re|ml)$/, use: 'bs-loader' },
      { test: /\.css$/, use: [ 'style-loader', 'css-loader' ]}
    ]
  },
  resolve: {
    // Add .re and .ml to the list of extensions webpack recognizes
    extensions: ['.re', '.ml', '.js']
  },
};
