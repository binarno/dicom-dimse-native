const addon = require('../index');

addon.startScp(JSON.stringify(
    {
        "source": {
            "aet": "IMEBRA",
            "ip" : "127.0.0.1",
            "port": "9999"
        },
	"storagePath": "./data"
    }   
    ), (result) => {
        try
        {
            console.log(JSON.parse(result));
        }
        catch {
            console.log(result);
        }
});


setTimeout(function() {
    addon.moveScu(JSON.stringify(
        {
            "source": {
                "aet": "IMEBRA",
                "ip" : "127.0.0.1",
                "port": "9999"
            },
            "target": {
                "aet": "CONQUESTSRV1",
                "ip" : "127.0.0.1",
                "port": "5678"
            },
            "tags" : [
                {
                    "key": "0020000D", 
                    "value": "1.3.46.670589.11.0.1.1996082307380006",
                },
                {
                    "key": "00080052", 
                    "value": "STUDY",
                },
            ],
            "destination" : "IMEBRA"
        }
    ), (result) => {
        try
        {
            console.log(JSON.parse(result));
        }
        catch {
            console.log(result);
        }
    });
    
    
        addon.moveScu(JSON.stringify(
        {
            "source": {
                "aet": "IMEBRA",
                "ip" : "127.0.0.1",
                "port": "9999"
            },
            "target": {
                "aet": "CONQUESTSRV1",
                "ip" : "127.0.0.1",
                "port": "5678"
            },
            "tags" : [
                {
                    "key": "0020000D", 
                    "value": "1.3.6.1.4.1.5962.99.1.2280943358.716200484.1363785608958.78.0",
                },
                {
                    "key": "00080052", 
                    "value": "STUDY",
                },
            ],
            "destination" : "IMEBRA"
        }
    ), (result) => {
        try
        {
            console.log(JSON.parse(result));
        }
        catch {
            console.log(result);
        }
    });

    
}, 3000);
