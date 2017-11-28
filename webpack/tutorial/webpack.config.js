const path = require('path');
const webpack = require('webpack')
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
    entry: './src/index.js',
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'static/[name].[chunkhash].js',
        chunkFilename: 'static/[id].[chunkhash].js',
    },
    devtool: 'inline-source-map',
    plugins: [
        new webpack.DefinePlugin({
                'process.env': {
                NODE_ENV: '"production"'
            }
        }),
        // split vendor js into its own file
        new webpack.optimize.CommonsChunkPlugin({
          name: 'vendor',
          minChunks: function (module) {
            // any required modules inside node_modules are extracted to vendor
            return (
              module.resource &&
              /\.js$/.test(module.resource) &&
              module.resource.indexOf(
                path.join(__dirname, '../node_modules')
              ) === 0
            )
          }
        }),

        // extract webpack runtime and module manifest to its own file in order to
        // prevent vendor hash from being updated whenever app bundle is updated
        new webpack.optimize.CommonsChunkPlugin({
          name: 'manifest',
          chunks: ['vendor']
        }),

        new HtmlWebpackPlugin({
            filename: 'index.html',
            template: 'index.html',
            inject: true,
            chunksSortMode: 'dependency'
        })

    ]
}
