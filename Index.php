<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initianal-scale=1.0">
    <link rel="stylesheet" href="styles.css">
    <script src="app.js"> </script>
    <title>IoT Irrigation System</title>
</head>
<body>
   <header>
       <h1>IoT Irrigation System</h1>
   </header>

   <section class="banner">
    <img src="img/banner.jpg" alt="welcome banner">
    <div class="welcome">
        <h2>Welcome to our <br><span>project</span> </h2>

    </div>
   </section>
   
   <main>
       <article>
       
           <h2 id="titlee">IoT Irrigation System Control Panel </h2>
          
       </article>
       <br>
       <p>Desired moisture <br> 0 is dry, 10 is wet.</p>
       <br>
       <div class="slidecontainer">
        <input type="range" min="0" max="1000" value="500" class="slider" id="sliderup">
      </div>
      <p id="outup">6</p>
      <br>
     
      <!-- <p>Info für de regler 2</p>
      <br>
      <div class="slidecontainer2">
        <input type="range" min="300" max="700" value="50" class="slider" id="sliderdown">
      </div>
      <p id="outdown">360</p>
       -->
      <br>
        <article2>
            <p>Currently measured moisture:</p>
            <h2 id="Currval">8</h2> 
        </article2>
        <!-- <svg id="svg1" xmlns="http://www.w3.org/2000/svg" style="width: 3.5in; height: 1in">
  <circle id="circle1" r="28" cx="34" cy="34" 
            style="fill: red; stroke: red; stroke-width: 2"/>
  </svg> -->
      <br>
      <button type="button" onclick="sendInfo()">Click to confirm!</button>
      <br>
      <br>
      
    
   </main>
  
    <footer>
       <p class="copyright">© 2020, SJF</p>
   </footer>
</body>
</html> 