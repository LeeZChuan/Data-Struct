import { getData } from "./7.promise";

test('获取异步', () => {
    return getData().then((res)=>{
        expect(res).toBe({
            "success":false
        })
    })
});


const flushPromises = () => new Promise(resolve => setImmediate(resolve));

test('enqueueJob should retry 6s after failing to run the job', async () => {
  const mockSetTimeout = jest.spyOn(window, 'setTimeout');
  mockSetTimeout.mockImplementation(() => {
    // Do nothing
  });
  const queue = new JobQueue();
  const job = new MockJob();
  job.run.mockImplementationOnce(async () => {
    throw new Error('Always fail');
  });
  queue.enqueueJob(job);
  await flushPromises();
  expect(job.run).toHaveBeenCalledTimes(1);
  expect(mockSetTimeout).toHaveBeenCalledTimes(1);
  const [handler, timeout] = mockSetTimeout.mock.calls[0];
  expect(typeof handler).toBe('function');
  expect(timeout).toEqual(6000);
  // Now run the handler
  handler();
  await flushPromises();
  expect(job.run).toHaveBeenCalledTimes(2);
});
