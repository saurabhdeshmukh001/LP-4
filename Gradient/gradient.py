x=2
lr=0.01
precision =0.000001
previous_step_size=1
max_iters=1000
iters=0
gf=lambda x:(x+3)**2

while precision<previous_step_size and iters<max_iters:
  prev=x
  x=x-lr*gf(prev)
  previous_step_size=abs(prev-x)
  iters+=1
  print('iteration:',iters,'value:',x)

print(x)