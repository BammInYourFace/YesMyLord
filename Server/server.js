var dgram = require('dgram');
var server = dgram.createSocket('udp4');

console.log("Socket created\n");
server.on("message",function (msg,rinfo) { 
  console.log("Received message:\n"+ msg.toString())+"\n";
  var response = "We gladly received your Message! Have a good day my friend :)";
  var responseBuffer = new Buffer(response.length);

  // Write the string to the buffer
  responseBuffer.write(response);

  // Send it back to the client, using the addressing information 
  // passed in via rinfo
  server.send(responseBuffer,0,responseBuffer.length,
              rinfo.port,rinfo.address,
    function(err, sent){
      if(err)
        console.log("Error sending response");
      else
        console.log("Responded to client at " + rinfo.address 
            + ":" + rinfo.port +"\n\n");

    });  
  }); 
server.bind(9000);