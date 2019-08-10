import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: appWindow
    visible:true
    flags:Qt.FramelessWindowHint
    width: 640
    height: 480

    property var createdViews: []

    Component.onCompleted: {
        loadView("qrc:/second.qml")
    }

    function loadView (viewFile, data) {
        var component = Qt.createComponent(viewFile)
        if (component.status === Component.Ready) {
            component.createObject(appWindow,{z: createdViews.length,x:10,y:0,viewData: data})
        }
    }
}
