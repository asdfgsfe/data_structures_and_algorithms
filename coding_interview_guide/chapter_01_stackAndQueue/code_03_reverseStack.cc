template<typename T>
T GetAndPopLast(stack<T>& values)
{
	assert(!values.empty());
	T val = values.top();
	values.pop();
	if (values.empty())
	{
		return val;
	}
	T last = GetAndPopLast(values);
	values.push(val);
	return last;
}

template<typename T>
void ReverseStack(stack<T>& values)
{
	if (values.empty())
	{
		return;
	}
	T last = GetAndPopLast(values);
	ReverseStack(values);
	values.push(last);
}