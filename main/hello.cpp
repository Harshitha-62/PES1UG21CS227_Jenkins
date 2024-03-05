// //File: hello.cpp
// #include <iostream>
// using namespace std;

// int main(void) {
//   cout << "Hello, World\n";
//   cout << "Hello, Jenkins\n";
//   cout << "I have successfully built and run\n";
//   return 0;
// }
pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        build 'PES1UG21CS227-1'
        sh 'g++ main.cpp -o output'
      }
    }
    stage('Test') {
      steps {
        sh './output'
      }
    }
    stage('Deploy') {
      steps {
        echo 'deploy'
      }
    }
  }
  post{
    failure{
      error 'Pipeline failed'
    }
  }
}
