const Sequelize = require('sequelize');
const config = require('./config');

var sequelize = new Sequelize(config.database, config.username, config.password, {
    host: config.host,
    dialect: 'mysql',
    pool: {
        max: 5,
        min: 0,
        idle: 30000
    },
    logging: true,
//    dialectOptions: {
//        "charset": "utf8mb4",
//        "collate": "utf8mb4_unicode_ci"
//    }
});

var User = sequelize.define('user', {
    id: {
        type: Sequelize.INTEGER(11),
        primaryKey: true,
        autoIncrement: true
    },
    name: Sequelize.STRING(255),
    info: Sequelize.TEXT
  }, {
        timestamps: false
  }
);


User.create({
    name: 'Gaffey😊',
    info: 'Gaffey😊'
}).then(function (p) {
    console.log('created.' + JSON.stringify(p));
}).catch(function (err) {
    console.log('failed: ' + err);
});

User.find({where:{id:30}}).then(function(result){
    console.log('%%%%%%%%%%');
    console.log('query.' + JSON.stringify(result));
    console.log('%%%%%%%%%%');
});
sequelize.query("show variables like '%char%'").spread(function (results, metadata) {
    console.log('query.' + JSON.stringify(results));
})

