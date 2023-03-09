import 'dart:math';

import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'package:play_guess_flag/ResultScreen.dart';

class QuizScreen extends StatefulWidget {
  QuizScreen();

  @override
  State<QuizScreen> createState() => _QuizScreenState();
}

class _QuizScreenState extends State<QuizScreen> {
  List<String> countries = [
    "Estonia",
    "France",
    "Germany",
    "Ireland",
    "Italy",
    "Monaco",
    "Nigeria",
    "Poland",
    "Russia",
    "Spain",
    "UK",
    "US",
  ];
  int yes=0;
  int no=0;
  int num=Random().nextInt(3);
  @override
  void initState() {//داله تمثل اول حاله بياخذه الاستست فل ودجت
    countries.shuffle();//عشان يغير ترتيب مصفوفه المدن ويصير كل مره مدن عشوائيه تطلع
    super.initState();
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.blueGrey,
      body: SafeArea(
        child: Center(
          child: Column(
            children: [
              SizedBox(height: 16),
              Text(
                "Guess The Flag?",
                style: TextStyle(
                  fontSize: 22,
                  color: Colors.white,
                ),
              ),
              Text(
                countries[num],
                style: TextStyle(
                  fontSize: 34,
                  color: Colors.white,
                  fontWeight: FontWeight.w700,
                ),
              ),
              SizedBox(height: 30),
              for(int i=0;i<3;i++)
                Padding(
                  padding: const EdgeInsets.only(bottom: 10.0),
                  child: FlagButton(
                    name: countries[i],
                    onPressed: () {
                      if(num==i) {
                        Fluttertoast.showToast(msg: "Correct Answer",backgroundColor: Colors.green,);
                        yes++;
                      }else{
                        Fluttertoast.showToast(msg: "Wrong Answer",backgroundColor: Colors.redAccent,);
                        no++;
                      }
                      setState(() {
                        countries.shuffle();
                        num=Random().nextInt(3);
                      });

                    },),
                ),
              ElevatedButton(onPressed: (){
                Navigator.push(context, MaterialPageRoute(builder: (context)=>ResultScreen(Yes:yes,No:no),),);
              }, child: Text("Result"))
            ],
          ),
        ),
      ),
    );
  }
}

class FlagButton extends StatelessWidget {
  const FlagButton({
    Key? key,
    required this.name,
    required this.onPressed,
  }) : super(key: key);

  final String name;
  final void Function() onPressed;
  @override
  Widget build(BuildContext context) {
    return TextButton(
      onPressed: onPressed,
        child: Image.asset(
      "assets/countries/$name.png",
      height: 130,
    ));
  }
}
