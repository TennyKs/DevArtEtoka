import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import 'package:flutter_webview_plugin/flutter_webview_plugin.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Data Viewer DevArt',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: WebViewGl(),
    );
  }
}

class WebViewGl extends StatefulWidget {
  WebViewGl();

  @override
  WebViewGlState createState() => WebViewGlState();
}

class WebViewGlState extends State<WebViewGl> {

  @override
  void initState(){
    super.initState();
    SystemChrome.setPreferredOrientations([
        DeviceOrientation.landscapeRight,
        DeviceOrientation.landscapeLeft,
    ]);
  }

  @override
  Widget build(BuildContext context) {
    return WebviewScaffold(
      url: "http://datisroom.byethost7.com",
    );
  }
}
