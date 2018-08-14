const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin'); //通过 npm 安装
const CleanWebpackPlugin = require('clean-webpack-plugin');


module.exports = {
  entry: {
    app: './src/index.js'
  },
  output: {
    path: path.resolve(__dirname, '../dist'),
    filename: '[name].bundle.[hash:8].js'
  },
  module: {
    rules: [
      {
        test: /\.(png|jpg|gif)$/,
        use: [
          {
            loader: 'url-loader',
            options: {
              limit: 8192,
              outputPath: 'img',
              name: '[name].[ext]'
            }
          }
        ]
      },
      {
        test: /\.(woff|woff2|eot|ttf|otf)$/,
        use: [
          {
            loader: 'file-loader',
            options:
            {
              name: '[name].[ext]',
              outputPath: 'fonts'
            }
          }
        ]
      }
    ]
  },
  plugins: [
    new CleanWebpackPlugin(['dist'], {root: path.resolve(__dirname, '..')}),
    new HtmlWebpackPlugin({ template: 'index.html' })
  ]
};
