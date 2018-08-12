const path = require('path');
const webpack = require('webpack');
const HtmlWebpackPlugin = require('html-webpack-plugin'); //通过 npm 安装
const CleanWebpackPlugin = require('clean-webpack-plugin');



const config = {
  mode: 'development',
  entry: './src/index.js',
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: '[name].bundle.[hash].js'
  },
  devtool: 'inline-source-map',
  devServer: {
    contentBase: './dist',
    hot: true
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: ['style-loader', 'css-loader']
      },
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
              name: '[name].[ext]'
            }
          }
        ]
      }
    ]
  },
  plugins: [
    new CleanWebpackPlugin(['dist']),
    new HtmlWebpackPlugin({template: 'index.html'}),
    new webpack.HotModuleReplacementPlugin(),
    new webpack.HotModuleReplacementPlugin()

  ]
};

module.exports = config;
