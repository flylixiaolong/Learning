#!/usr/bin/env node
var amqp = require('amqplib/callback_api');
var message;
var chh;
var q = 'hello';

amqp.connect('amqp://localhost', function(err, conn) {});
amqp.connect('amqp://localhost', function(err, conn) {
  conn.createConfirmChannel(function(err, ch) {
    chh=ch;

    ch.on('error', function(error) {
      console.log('ch==>error', error);
      console.log(message);
    })
    ch.on('close', function(error) {
      console.log('ch==>close', error);
      console.log(message);
    })

    ch.assertQueue(q, {durable: true});
  });
  conn.on('error', function(error) {
    console.log('conn==>error', error);
    console.log(message);
  })
  conn.on('close', function(error) {
    console.log('conn==>close', error);
    console.log(message);
  })
});

var i=1;
function sendMsg(){
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      // Note: on Node 6 Buffer.from(msg) should be used
      var ok = true;
      var send = true;
      while(ok && i<= 200000 && send){
        message = `${i}`;
        ok = chh.sendToQueue(q, new Buffer(JSON.stringify(message)), {persistent: true}, (function(z){
          return function(err, ok) {
            if (err !== null){
              // console.log(z, 'no', ok);
            }
            else {
              // console.log(z, 'ok', ok);
            }
          }
        })(i))
        chh.waitForConfirms((function(z){
          send=false;
          return function(err){
            send = true;
            console.log(z, 'ok', err);
          }
        })(i))
        if(ok){
          console.log(i, 'yes-all', ok);
        }
        i = i+1;
      }
      setTimeout(()=>{
        sendMsg();
      }, 0);
    }, 0);
  });
}

setTimeout(sendMsg, 1000);
