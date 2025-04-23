play=input('if you want to play enter "yes", if you dont enter "no" or "0",("any time during the game if u want to finish type "0""): ') 
if play=='no' or '0' and play!='yes':
    w=input('are you sure you want to abort game? if yes enter "0",if no enter "continue": ')
    if w=='0':
        print('GAME ABORTED(NO BABIES)')
    else:
        play=input('if you want to play another game enter "yes", if not enter "no": ')
while play=="yes" and play!=0: 
    k=input("if you want you want to guess enter '1', if want machine to guess enter '2': ")
    if k=='0':
        w=input('are you sure you want to abort game? if yes enter "0",if no enter "continue": ')
        if w=='0':
            print('GAME ABORTED(NO BABIES)')
            break
        elif w=='continue':
            continue       
    lower_limit, upper_limit = 1, 999   
    if k=='1':
        import random
        num=random.randint(lower_limit, upper_limit)
        def func():
            s=0
            guess=int(input('guess the number: '))
            while guess != num:
                s=s+1
                if guess==0:
                    w=input('are you sure you want to abort game? if yes enter "0",if no enter "continue": ')
                    if w=='0':
                        print('GAME ABORTED(NO BABIES)')
                        break
                    elif w=='continue':
                        continue
                    
                elif guess>num:
                    print ("real number is smaller than ",guess)
                    guess=int(input('guess the number: '))
                elif guess<num:
                    print("real number is bigger than ",guess)
                    guess=int(input('guess the number: '))
                else:
                    break
            if num==guess:
                print('correct! number of attempts: ', s, num)          
        func()
    elif k=='2':
        import random
        num=int(input('give a num: '))
        if num==0:
            w=input('are you sure you want to abort game? if yes enter "0",if no enter "continue": ')
            if w=='0':
                print('GAME ABORTED(NO BABIES)')
                break
            elif w=='continue':                    
                continue
        def func():
            lower_limit, upper_limit=1,999   #replace 999 with 9999 for ex 2.4
            s=1
            letter='first'
            while letter=='s'or letter=='S'or letter== 'b'or letter=='B' or letter=='first' or letter=='=' or letter=='<' or letter=='>':
                guess=random.randint(lower_limit,upper_limit)
                print (guess)
                letter=input('if guessed num is smaller enter "s", if guessed num is bigger enter"b", if found enter"f":')
                if letter=='0':
                    w=input('are you sure you want to abort game? if yes enter "0",if no enter "continue": ')
                    if w=='0':
                        print('GAME ABORTED(NO BABIES)')
                        break
                    elif w=='continue':
                        continue 
                                                  
                if letter=='s' or letter=='S' or letter=='<':
                    lower_limit= guess+1
                    if((letter=='s' or letter=='S' or letter=='<') and guess>=num):
                        print('cheater')
                        break

                elif letter== 'b' or letter== 'B' or letter=='>':
                    upper_limit=guess-1
                    if ((letter== 'b' or letter== 'B' or letter=='>') and guess<=num):
                        print('cheater')
                        break
                elif letter=='f' or letter=='F' or letter=='=':
                    if num!=guess:
                        print("cheater")
                    else:                            
                        print ('number of attemts: ',s)
                        break  
                s+=1     

        func()
    play=input('if you want to play another game enter "yes", if not enter "no" or "0": ')
    if play in ['no', '0'] and play != 'yes':
        w=input('are you sure you want to abort game? if yes enter "0",if no enter "continue": ')
        if w=='0':
            print('GAME ABORTED(NO BABIES)')
        else:
            play=input('if you want to play another game enter "yes", if not enter "no": ')
