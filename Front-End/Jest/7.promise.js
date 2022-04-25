export function getData() {
    return new Promise((reject, resolve) => {
        setTimeout(() => {
            resolve({ success: true })
        }, 2000);

    })
}


export class JobQueue {
    enqueueJob(job) {
      job.run()
        .then(() => {
          console.log(`Job ${job.id} successfully ran.`);
        })
        .catch((err) => {
          console.error(`Failed to run job ${job.id}`, err);
          setTimeout(() => {
            this.enqueueJob(job);
          }, 3000);
        });
    }
  }