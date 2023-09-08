import QtQuick
import QtQuick.Controls

Item
{
    id: log_view
    width: 1280
    height: 200
    opacity: 1

    Text {
        id: logger_text
        width: parent.width
        height:parent.height
        color: "#ff0000"
        wrapMode: Text.WordWrap
        text: "<b>Hello</b><i>World!</i><br>"
        font.pixelSize: 15
        textFormat: Text.RichText

        property bool dataChanged: parent.parent.mainDataChanged
        onDataChangedChanged: {
            if(dataChanged)
            {
                load_data();
                dataChanged = false;
                parent.mainDataChanged = false;
            }
        }
    }

    Button{
        id: b1
        x: 600
        y: 50
        width: 100
        height: 50
        text: "Click!!!"
        font.pixelSize: 20
        onClicked: {
            console.log(parent.mainDataChanged)
            console.log(logger_text.dataChanged)
            load_data()
        }
    }

    function load_data(){
        
        switch(Logger_text.Type)
        {
            case 0:
                logger_text.text += '<font color="#00ff00">[INFO]: '+ Logger_text.Info + '</font>' + "<br>";
                break;
            case 1:
                logger_text.text += '<font color="#0000ff">[FATAL]: ' + Logger_text.Info + '</font>' + "<br>";
                break;
            case 2:
                logger_text.text += '<font color="#00ffff">' + "[WARNING]: " + Logger_text.Info + '</font>' + "<br>";
                break;
            case 3:
                logger_text.text += '<font color="#ff0000">' + "[ERROR]: " + Logger_text.Info + '</font>' + "<br>";
                break;
        }
    }
}
