const maxHum= 800
const humPerUnit=50


window.onload = function() {
    
    var sliderup = document.getElementById("sliderup");
    var sliderdown = document.getElementById("sliderdown")
    var outup = document.getElementById("outup");
    var outdown= document.getElementById("outdown");
    var currval= document.getElementById("Currval");

    
    var up = httpGet("api.php?get=up")
    var scalUp = valToScala(up)
    console.log(up)
    sliderup.value = scalUp
    
    // sliderdown.value = httpGet("api.php?get=down")/100
    currval=httpGetAsync("api.php?get=val",setVal)
    
    outup.innerHTML = Math.round(sliderup.value/100*10)/10;
    setColor()


    // outdown.innerHTML = sliderdown.value;
// Update the current slider value (each time you drag the slider handle)
sliderup.oninput = function() {
  outup.innerHTML = Math.round(sliderup.value/100*10)/10;
 
}

window.setInterval(function(){
  // sendInfo()
  var valurl= "api.php?get=val"
  httpGetAsync(valurl,setVal)
  checkAvalib
}, 3000);
}

function checkAvalib(){
  httpGetAsync("api.php?get=time",setColor)
}

function setColor(val){
  if(val>20){
    document.getElementById("Currval").style.color="red"
  }else{
    document.getElementById("Currval").style.color="black"
  }

  
  // .style.fill='yellow';
}

function scalaToVal(scal){
  console.log(scal)
  ret = Math.round((maxHum-(scal/100*humPerUnit)))
  console.log(ret)
  return ret


}
function valToScala(val){
  ret= Math.round((((maxHum-val)/50)*100));
  console.log(ret)
  return ret
}

// 0 is dry -->800
//1 --> 750
//2 --> 700
//3 --> 650
//4 --> 600
//5 --> 550
//6 --> 500
//7 --> 450
//8 --> 400
//9 --> 350
//10 --> 300

//10 is Wet



function sendInfo() {
  var upScal=document.getElementById("sliderup").value
  // var downScal=document.getElementById("sliderdown").value
  var up = scalaToVal(upScal)
  var down = up-60
  // var host = window.location.host;
  var host = ""
  var apidoc = host+"api.php?";
  var upurl=apidoc+"up="+up;
  console.log(upurl)
  

  var downurl=apidoc+"down="+down;
  var valurl=apidoc+"get=val";

  httpGetAsync(upurl,nothing)
  httpGetAsync(downurl,nothing)
  httpGetAsync(valurl,setVal)

  }

function setVal(val){
  // var valScal = valToScala()
  scalVal=Math.round(valToScala(val)/10)*10/100
  document.getElementById("Currval").innerHTML = scalVal;

}

function nothing(a){
  null
}

function httpGet(theUrl)
{
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open( "GET", theUrl, false ); // false for synchronous request
    xmlHttp.send( null );
    return xmlHttp.responseText;
}
   
function httpGetAsync(theUrl, callback)
{
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.onreadystatechange = function() { 
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200)
            callback(xmlHttp.responseText);
    }
    xmlHttp.open("GET", theUrl, true); // true for asynchronous 
    xmlHttp.send(null);
}

