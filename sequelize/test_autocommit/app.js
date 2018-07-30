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
    dialectOptions: {
        "charset": "utf8mb4",
        "collate": "utf8mb4_unicode_ci"
    }
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


sequelize.transaction({
   autocommit:true
}).then(function(t){
   return User.create({
       name: 'Gaffey1',
       info: 'Gaffey😊'
   },{transaction: t});
}).then(function (p) {
    console.log('created.' + JSON.stringify(p));
}).catch(function (err) {
    console.log('failed: ' + err);
});

setTimeout(function(){
  User.findAll().then(function(result){
    console.log('%%%%%%%%%%');
    console.log('query.' + JSON.stringify(result));
    console.log('%%%%%%%%%%');
  });
},5000);

sequelize.transaction({
  autocommit:false
}).then(function(t){
  return User.create({
      name: 'Gaffey2',
      info: 'Gaffey😊'
    },{transaction: t
  }).then(function (p) {
      t.commit();
      console.log('created.' + JSON.stringify(p));
  }).catch(function (err) {
      t.rollback();
      console.log('failed: ' + err);
  });
});

setTimeout(function(){
    User.findAll().then(function(result){
        console.log('%%%%%%%%%%');
        console.log('query.' + JSON.stringify(result));
        console.log('%%%%%%%%%%');
    });
},5000);

sequelize.transaction({
  autocommit:false
}, function(t){
  return User.create({
      name: 'Gaffey3',
      info: 'Gaffey😊'
    },{
      transaction: t
  }).then(function (p) {
      console.log('created.' + JSON.stringify(p));
  }).catch(function (err) {
      console.log('failed: ' + err);
  });
});

setTimeout(function(){
    User.findAll().then(function(result){
        console.log('%%%%%%%%%%');
        console.log('query.' + JSON.stringify(result));
        console.log('%%%%%%%%%%');
    });
},5000);


sequelize.transaction({
  autocommit:true
}, function(t) {
  return User.create({
      name: 'Gaffey4',
      info: 'Gaffey😊'
    },{
    transaction: t
  }).then(function (p) {
      console.log('created.' + JSON.stringify(p));
  }).catch(function (err) {
      console.log('failed: ' + err);
  });
});

setTimeout(function(){
    User.findAll().then(function(result){
        console.log('%%%%%%%%%%');
        console.log('query.' + JSON.stringify(result));
        console.log('%%%%%%%%%%');
    });
},5000);
