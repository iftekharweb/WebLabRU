import { useEffect, useState } from 'react'
import './App.css'

function App() {
  const [count, setCount] = useState(0)
  const arr = ['No', 'Are you sure?', 'Really? Sure?', 'Think again please!', 'Really really sure??????', 'Last time: NO?']

  const handleClick = () => {
    if(count == arr.length-1) {
      setCount(0);
    } else {
      setCount(count+1);
    }
  }

  return (
    <>
    {
      
    }
      <div className='conatainer'>
        <div>
          <h1>Will you be my valentine?</h1>
        </div>
        <div>
          <button onClick={handleClick}>
            <h1>{arr[count]}</h1>
          </button>
        </div>
      </div>
    </>
  )
}

export default App
