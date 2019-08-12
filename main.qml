import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480

    Button{
        id:loadUrl
        text: "测试加载url"
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        onClicked: {
            //调用C++ 的方法
            $SigDispatcher.loadUrl();
        }
    }
    Button{
        id:msgQueue
        text: "消息队列"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: loadUrl.right
        anchors.leftMargin: 10
        onClicked: {
            //调用C++ 的方法
            $SigDispatcher.msgQueueSend("hello world");
        }
    }

    property var pageOne
    function loadView (viewFile, data) {
        var component = Qt.createComponent(viewFile)
        if (component.status === Component.Ready) {
           pageOne= component.createObject(applicationWindow,{viewData: data})
        }
        else
            console.error("Error loading view:", component.errorString())
    }

    Button {
        id:openTestJs
        x: 10
        y: 57
        text: "openTestJs"
        onClicked: {
//            loadButton("qrc:/second.qml")
            loadView("qrc:/second.qml",["a","2"])
        }
    }

    Button {
        id: button
        x: 104
        y: 57
        text: qsTr("close")
        onClicked: {
            if (pageOne != null){
                pageOne.destroy()
            }
        }
    }

    Button {
        id: button1
        x: 10
        y: 103
        text: qsTr("发起一次会话")
        onClicked: {
             $SigDispatcher.createReqSession("hello session");
        }
    }


}
