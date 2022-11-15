Bankingapplication app;
    char cond = 'y';
    while (cond != 'n'){
        app.run();
        cout << "Do you want to continue (y/n)=========>";
        cin >> cond;
    }