#ifndef AAA_INVERTERS_H
#define AAA_INVERTERS_H

#include <pgmspace.h>
#include "ESP-ECU.h"

const char INV_SCRIPT[] PROGMEM = R"=====(
function showFunction() {
  //alert("showFunction");
  document.getElementById("invspan").style.display = "inline";
}
function hideFunction() {
  //alert("showFunction");
  document.getElementById("invspan").style.display = "none";
}
function myFunction(){
 if(document.getElementById("sel").value == 1 ) { 
    showFunction();
 } else {
   hideFunction();
 }
}

function delFunction(a) {
  if(confirm("are you sure to delete this inverter ?")) {  
  document.getElementById("bo").innerHTML="<br>wait...<br>processing<br>your<br>request"; 
  document.getElementById("bo").style.display="block";
  document.getElementById('formular').submit();   
  setTimeout(function(){window.location.href=a;}, 3000 ); 
  }
}

)====="; 

const char INVCONFIG_START[] PROGMEM = R"=====(
<!DOCTYPE html><html><head><meta charset='utf-8'>
<title>ESP-ECU</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" type="image/x-icon" href="/favicon.ico" />
<link rel="stylesheet" type="text/css" href="/STYLESHEET_HOME">
<link rel="stylesheet" type="text/css" href="/STYLESHEET_SUBS">
<script type='text/javascript'>

function showSubmit() {
document.getElementById("sub").style.display = "block";
}
function submitFunction(a) {
document.getElementById("bo").innerHTML="<br>wait...<br>saving<br>this<br>inverter"; 
document.getElementById("bo").style.display="block"; 
document.getElementById('formulier').submit();
setTimeout(function(){window.location.href=a;}, 3000 ); 
}
</script>
<style>
.cap {
  font-weight:bold; 
  Background-color:lightgreen;
 }
div.overlay {
  display: block;
  width: 100%;
  height: 100%;
  background-color: rgba(0,0,0,0.7);
  z-index: 0;
  text-align: center;
  vertical-align: middle;
  line-height: 300px;
}
</style>
<script>
function cl() {
window.location.href='/MENU';
}
</script>
</head>
<body onload='%LOADBAG%'>

<center>

<div id='msect'>
<ul>
<li id='fright'><span class='close' onclick='cl();'>&times;</span>
<li><a href='/INV?welke=0' style='display:%none'0%>inv. 0</a></li>
<li><a href='/INV?welke=1' style='display:%none'1%>inv. 1</a></li>
<li><a href='/INV?welke=2' style='display:%none'2%>inv. 2</a></li>
<li><a href='/INV?welke=3' style='display:%none'3%>inv. 3</a></li>
<li><a href='/INV?welke=4' style='display:%none'4%>inv. 4</a></li>
<li><a href='/INV?welke=5' style='display:%none'5%>inv. 5</a></li>
<li><a href='/INV?welke=6' style='display:%none'6%>inv. 6</a></li>
<li><a href='/INV?welke=7' style='display:%none'7%>inv. 7</a></li>
<li><a href='/INV?welke=8' style='display:%none'8%>inv. 8</a></li>
<li><a href='/INV?welke=99' style='display:%none'99%>add</a></li>
</ul>
</div>

<div id='msect'>
<div id='bo'></div>
  <center><div class='divstijl' style='height:64vh;'>
<form id='formulier' method='get' action='inverterconfig' oninput='showSubmit()' onsubmit="return confirm('sure to save this inverter?')">
  
    %<FORMPAGE>%
    <br>
  </div>
</div>
<div id='msect'>
  <form id='formular' method='get' action='/INV_DEL'></form>
  <ul>
  <div id='pairknop' style='display:%none'p% >
    <li ><a class='groen' href='/PAIR' onclick="return confirm('Are you sure you want to pair this inverter?')">pair</a></li>
    <li><a href='#' onclick='delFunction("/SW=BACK")'>delete</a></li>
  </div>
    <li><a href='#' onclick='helpfunctie()'>help</a></li>
    <li id='sub'><a href='#' onclick='submitFunction("/SW=BACK")'>save</a></li>
  
</div>  
</ul>
<br>
  
</div>
<script type="text/javascript" src="INVSCRIPT"></script>
</body></html>
 )=====";

void inverterForm();

void handleInverterdel(AsyncWebServerRequest *request);
void handleInverterconfig(AsyncWebServerRequest *request);

String processor(const String& var);

#endif