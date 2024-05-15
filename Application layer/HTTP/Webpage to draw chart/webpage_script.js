var UPDATE_INTERVAL = 20; // Data update interval is UPDATE_INTERVAL ms
var xhttp = new XMLHttpRequest();

main();

window.onload = main;

function main() {
	var sineValue = [];
    var Chart = new CanvasJS.Chart("ChartContainer", {
        zoomEnabled: true, // Graph zoom enable
        title: {
            text: "Sinewave chart" // Graph title
        },
        axisX: {
            title: "Time axis" // Legend for X-axis
        },
        axisY:{
            minimum: -1,
            maximum: 1
        },
        data: [{
                // Define value chart
                type: "line",
                xValueType: "dateTime", // X-axis value's type is dateTime
                showInLegend: true, // Show legend "Sinewave"
                name: "Sinewave value",
                dataPoints: sineValue // Data got from sineValue
            }
            ],
        });

    function updateChart() {
        var ySineVal = 0; // Save humidity value into Y-axis
        var time = new Date(); // Get current time

        httpGetAsync('/tx_to_js_webpage', function(data) {
            console.log(data);// Debug value received from HTTP server

            // Update time and get sinewave value from server
            time.setTime(time.getTime() + UPDATE_INTERVAL);
            ySineVal = parseFloat(data);
            sineValue.push({// Update new data from server
                x: time.getTime(),
                y: ySineVal
            });
            Chart.render();// Render graph data into chart
        });
    };

    updateChart(); // First run
    setInterval(updateChart, UPDATE_INTERVAL);// Update graph data after UPDATE_INTERVAL
}

function httpGetAsync(theUrl, callback) { 
    var xmlHttp = new XMLHttpRequest();
    
    xmlHttp.onreadystatechange = function() {
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200){
            callback(xmlHttp.responseText);
        }        
    }

    xmlHttp.open("POST", theUrl, true); // true for asynchronous
    
    xmlHttp.send();
}
